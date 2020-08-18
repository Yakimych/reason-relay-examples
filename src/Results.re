module Query = [%relay.query
  {|
    query ResultsQuery {
      results_connection(where: { community: { name: { _eq: "test" } } }) {
        edges {
          node {
            ...Result
            id
          }
        }
      }
    }
  |}
];

module AddResultMutation = [%relay.mutation
  {|
    mutation Results_AddResultMutation {
      insert_results_one(
        object: {
          community: {
            data: { name: "test2" }
            on_conflict: { constraint: communities_name_key, update_columns: name }
          }
          player1Id: 203
          player2Id: 208
          player1goals: 3
          player2goals: 2
          date: "2020-01-01"
          extratime: false
        }
      ) {
        id
        player1 {
          name
        }
        player1goals
        player2 {
          name
        }
        player2goals
        community {
          name
        }
      }
    }
  |}
];

[@react.component]
let make = () => {
  let queryData = Query.use(~variables=(), ~fetchPolicy=StoreOrNetwork, ());
  let results = queryData.results_connection.edges;

  <div>
    <div className="header">
      <h1> {React.string("Header")} </h1>
      <button onClick={_ => ReasonReactRouter.push("communities")}>
        {React.string("Communities")}
      </button>
    </div>
    <h3> {React.string("Results")} </h3>
    {results->Belt.Array.map(result =>
       <Result result={result.node.fragmentRefs} key={result.node.id} />
     )
     |> React.array}
  </div>;
};
