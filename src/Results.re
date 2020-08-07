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

[@react.component]
let make = () => {
  let queryData = Query.use(~variables=(), ());
  let results = queryData.results_connection.edges;

  <div>
    <button onClick={_ => Js.log("Clicked on 'Add'")}>
      {React.string("Add")}
    </button>
    <h3> {React.string("Results")} </h3>
    {results->Belt.Array.map(result =>
       <Result result={result.node.fragmentRefs} key={result.node.id} />
     )
     |> React.array}
  </div>;
};
