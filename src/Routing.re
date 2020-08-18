[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  <main>
    <div>
      {switch (url.path->Belt.List.map(Js.Global.decodeURI)) {
       | ["communities"] =>
         <React.Suspense
           fallback={<div> {React.string("Loading communities...")} </div>}>
           <Communities />
         </React.Suspense>
       | ["results"] =>
         <React.Suspense
           fallback={<div> {React.string("Loading results...")} </div>}>
           <Results />
         </React.Suspense>
       | _ =>
         <div>
           <button onClick={_ => ReasonReactRouter.push("communities")}>
             {React.string("Communities")}
           </button>
           <button onClick={_ => ReasonReactRouter.push("results")}>
             {React.string("Results")}
           </button>
           <span> {React.string("Route not found")} </span>
         </div>
       }}
    </div>
  </main>;
};
