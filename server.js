const express = require("express");
const cors = require("cors");
const { exec } = require("child_process");
const path = require("path");

const app = express();

app.use(cors());
app.use(express.json());

// ✅ Serve your HTML file
app.use(express.static(__dirname));

// ✅ API to run C++ program
app.post("/run", (req, res) => {
    const { type, data } = req.body;

    if (!type || !data) {
        return res.send("Invalid request");
    }

    // join input safely
    let input = data.join(" ");

    // IMPORTANT: use ./app.exe
    let command = `.\\app.exe ${type} ${input}`;

    exec(command, (err, stdout, stderr) => {
        if (err) {
            console.log(err);
            return res.send("Error running C++");
        }
        res.send(stdout);
    });
});

// ✅ Fix for "Cannot GET /"
app.get("/", (req, res) => {
    res.sendFile(path.join(__dirname, "index.html"));
});

app.listen(3000, () => {
    console.log("Server running at http://localhost:3000");
});