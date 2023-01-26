import express from 'express';
import bodyParser from 'body-parser';
import mongoose from 'mongoose';
import mysql2 from 'mysql2';
import cors from 'cors';


const app  = express();
const router = express.Router();

app.use(bodyParser.json({ limit: "30md", extended: true}));
app.use(bodyParser.urlencoded({ limit: "30md", extended: true}));
app.use(cors());

const PORT = 5000   ;



var con = mysql2.createConnection({
    host: "localhost",
    port: 3306,
    database: "users",
    user: "rocky",
    password: ""
  });


app.listen(PORT, () => {
    console.log(`Started on port ${PORT}`);
});

app.get('/', (req, res) => {
    res.send("This works");
})


app.get('/employees', (req, res) => {
    var sql = "SELECT * FROM employees;"
    con.connect(function(err) {
      if (err) throw err;
      console.log("Connected!");
      con.query(sql, function (err, result) {
          if (err) throw err;
          res.send(result);
        });
    });
})

app.get('/students', (req, res) => {
    var sql = "SELECT * FROM students;"
    con.connect(function(err) {
      if (err) throw err;
      console.log("Connected!");
      con.query(sql, function (err, result) {
          if (err) throw err;
          res.send(result);
        });
    });
})



