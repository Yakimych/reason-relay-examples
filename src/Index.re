[%bs.raw {|require("./index.css")|}];

ReactExperimental.renderConcurrentRootAtElementWithId(
  <ReasonRelay.Context.Provider environment=RelayEnv.environment>
    <App />
  </ReasonRelay.Context.Provider>,
  "root",
);

// ReactDOMRe.renderToElementWithId(<App />, "root");
