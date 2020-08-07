[@react.component]
let make = () => {
  <main>
    {React.string("ReasonRelay examples")}
    <div>
      <React.Suspense fallback={<div> {React.string("Loading...")} </div>}>
        <Communities />
        <Results />
      </React.Suspense>
    </div>
  </main>;
};
