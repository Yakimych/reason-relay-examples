module Query = [%relay.query
  {|
    query ResultsQuery {
      results_connection(where: { community: { name: { _eq: "test" } } }) {
        edges {
          node {
            ...Result
          }
        }
      }
    }
  |}
];

[@react.component]
let make = () => {
  let queryData = Query.use(~variables=(), ());
  let results = queryData.results_connection.edges;

  let resultsWithAttachedRatings = results |> Array.mapi((i, r) => (r, i));
  <div>
    <span>
      {React.string(
         "Number of results: " ++ results->Belt.Array.length->string_of_int,
       )}
    </span>
    <h3> {React.string("Results")} </h3>
    {resultsWithAttachedRatings->Belt.Array.map(((result, rating)) =>
       <Result result={result.node.fragmentRefs} rating />
     )
     |> React.array}
  </div>;
};
