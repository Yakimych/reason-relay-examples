[%bs.raw {|require("./index.css")|}];

ReactExperimental.renderConcurrentRootAtElementWithId(
  <ReasonRelay.Context.Provider environment=RelayEnv.environment>
    <Routing />
  </ReasonRelay.Context.Provider>,
  "root",
);

// ReactDOMRe.renderToElementWithId(<App />, "root");
