module Query = [%relay.query
  {|
    query CommunitiesQuery {
      communities_connection(first: 1000, where: { name: { _like: "%test%" } })
        @connection(
          key: "CommunityList_query_communities_connection"
          filters: ["where"]
        ) {
        edges {
          node {
            ...Community
            id
          }
        }
      }
    }
  |}
];

module AddCommunityMutation = [%relay.mutation
  {|
    mutation Communities_AddCommunityMutation($communityName: String!) {
      insert_communities_one(object: { name: $communityName }) {
        id
        name
      }
    }
  |}
];

[@react.component]
let make = () => {
  let queryData = Query.use(~variables=(), ());
  let communities = queryData.communities_connection.edges;
  let communityIds = communities->Belt.Array.map(e => e.node.id);

  let lastRenderedCommunityIds = React.useRef(Js.Nullable.null);

  Js.log("Community: render called");
  Js.log2("Community ids: ", communityIds);
  Js.log2("Last rendered community ids: ", lastRenderedCommunityIds.current);
  lastRenderedCommunityIds.current =
    Some(communityIds)->Js.Nullable.fromOption;

  let (communityName, setCommunityName) = React.useState(() => "");

  let mutationVariables = AddCommunityMutation.makeVariables(~communityName);

  let (mutate, _isMutating) = AddCommunityMutation.use();

  let addCommunity = () => {
    mutate(
      ~variables=mutationVariables,
      ~updater=
        (store, _response) => {
          ReasonRelayUtils.(
            switch (
              resolveNestedRecord(
                ~rootRecord=
                  store->ReasonRelay.RecordSourceSelectorProxy.getRootField(
                    ~fieldName="insert_communities_one",
                  ),
                ~path=[],
              )
            ) {
            | Some(node) =>
              createAndAddEdgeToConnections(
                ~store,
                ~node,
                ~connections=[
                  {
                    parentID: ReasonRelay.storeRootId,
                    key: "CommunityList_query_communities_connection",
                    filters:
                      Some(
                        ReasonRelay.makeArguments({
                          "where": {
                            "name": {
                              "_like": "%test%",
                            },
                          },
                        }),
                      ),
                  },
                ],
                ~edgeName="communitiesEdge",
                ~insertAt=End,
              )
            | None => Js.log("resolveNestedRecord returned None")
            }
          )
        },
      (),
    )
    |> ignore;
  };

  <div>
    <input
      type_="text"
      onChange={e => {
        let newText = ReactEvent.Form.target(e)##value;
        setCommunityName(newText);
      }}
      value=communityName
    />
    <h3> {React.string("Communities")} </h3>
    <button onClick={_ => addCommunity()}> {React.string("Add")} </button>
    {communities->Belt.Array.map(community =>
       <Community
         community={community.node.fragmentRefs}
         key={community.node.id}
       />
     )
     |> React.array}
  </div>;
};
