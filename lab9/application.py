import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        aName = request.form.get("name")
        aMonth = request.form.get("month")
        aDay = request.form.get("day")

        db.execute("INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?)", aName, aMonth, aDay)

        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html

        DATA = db.execute("SELECT * FROM birthdays")

        return render_template("index.html", data = DATA)


