import express from 'express';
import bodyParser from 'body-parser';
import mongoose from 'mongoose';
import cors from 'cors';


const app = express();
const router = express.Router();

app.use(bodyParser.json({ limit: "30mb", extended: true }));
app.use(bodyParser.urlencoded({ limit: "30mb", extended: true }));
app.use(cors());

const PORT = 5000;
const DATABASE_URL = "mongodb://localhost:27017/users";

const employeeSchema = mongoose.Schema({
    id: Number,
    name: String,
    password: String
});

const studentsSchema = mongoose.Schema({
    id: Number,
    name: String,
    course: String,
    age: Number
});


mongoose.connect(DATABASE_URL, { useNewUrlParser: true, useUnifiedTopology: true })
    .then(() => { app.listen(PORT, () => { console.log(`Started on port ${PORT}`) }) })
    .catch((error) => console.log(error.message));

const employeeModel = mongoose.model('employees', employeeSchema);
const studentModel = mongoose.model('students', studentsSchema);


app.get('/', (req, res) => {
    res.send("This works");
})


app.get('/employees', (req, res) => {
    try {
        employeeModel.find({})
            .then(data => {
                res.send(data);
            })
    } catch (error) {
        console.log(error);
    }
});

app.get('/employees/:id', (req, res) => {
    employeeModel.find({ "id": req.params.id })
        .then(data => {
            res.send(data);
        })
})

app.get('/students', (req, res) => {
    studentModel.find({})
        .then(data => {
            res.send(data)
        })
});

app.get('/students/:id', (req, res) => {
    studentModel.find({ "id": req.params.id })
        .then(data => {
            res.send(data)
        })
});

app.post('/employees', (req, res) => {
    try {
        employeeModel.insertMany(req.body, (err, res2) => {
            if (err) throw err;
            res.send("Employee added");
        })
    } catch (error) {
        console.log(error);
    }
})

app.delete('/employees/:id', (req, res) => {
    try {
        employeeModel.deleteOne(req.body, (err, res2) => {
            if (err) throw err;
            res.send("employee deleted");

        })
    } catch (error) {
        
    }
})

app.patch('/employees/:id', (req, res) => {
    try {
        employeeModel.updateOne({id: req.params.id} ,req.body, (err, res2) => {
            if (err) throw err;
            res.send(res2);
        })
    } catch (error) {
        
    }
})

