module.exports = {
  modelBaseDirectory: "app_api/models",
    models: ["*.js", "!db.js"], // model matcher
    data: "data", // data directory name
    db: "mongodb://127.0.0.1:27017/travlr", // db connection url
  };