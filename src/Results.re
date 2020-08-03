module Query = [%relay.query
  {|
    query ResultsQuery {
      results_connection(where: { community: { name: { _eq: "test" } } }) {
        edges {
          node {
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
      }
    }
  |}
];

let renderResult =
    (
      result: ResultsQuery_graphql.Types.response_results_connection_edges_node,
    ) =>
  <div key={result.id}>
    <span className="playercol"> {React.string(result.player1.name)} </span>
    <span className="goalscol">
      {React.string(result.player1goals |> string_of_int)}
    </span>
    <span> {React.string(" - ")} </span>
    <span className="goalscol">
      {React.string(result.player2goals |> string_of_int)}
    </span>
    <span className="playercol"> {React.string(result.player2.name)} </span>
  </div>;

[@react.component]
let make = () => {
  let queryData = Query.use(~variables=(), ());

  <div>
    <span>
      {React.string(
         "Number of results: "
         ++ queryData.results_connection.edges
            ->Belt.Array.length
            ->string_of_int,
       )}
    </span>
    <h3> {React.string("Results")} </h3>
    {queryData.results_connection.edges
     ->Belt.Array.map(result => renderResult(result.node))
     |> React.array}
  </div>;
};
