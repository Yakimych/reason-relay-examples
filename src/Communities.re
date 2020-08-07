module Query = [%relay.query
  {|
    query CommunitiesQuery {
      communities_connection {
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

  let (communityName, setCommunityName) = React.useState(() => "");

  let mutationVariables = AddCommunityMutation.makeVariables(~communityName);

  let (mutate, _isMutating) = AddCommunityMutation.use();

  let addCommunity = () => {
    mutate(~variables=mutationVariables, ()) |> ignore;
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
