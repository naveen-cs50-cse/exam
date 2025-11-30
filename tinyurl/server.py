from flask import Flask, send_file, abort
import os

app = Flask(__name__)
DB_FILE = "db.txt"

def read_db():
    data = {}
    if os.path.exists(DB_FILE):
        with open(DB_FILE, "r") as f:
            for line in f:
                code, path = line.strip().split("|")
                data[code] = path
    return data

@app.route("/<code>")
def download(code):
    db = read_db()
    if code not in db:
        return abort(404)

    zip_path = db[code].replace("/", "\\")

    if not os.path.exists(zip_path):
        return abort(404)

    return send_file(zip_path, as_attachment=True)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5005)
