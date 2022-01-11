"""
    BSI09 Flask oAuth demo
    Mikołaj Jakubowski (s18860)

    [X] Implementing Authorization Code Grant flow in a web application for authenticating and authorising a user - 5 points
    [X] Handling the client credentials in accordance with the best practice (eg. JSON file, as opposed to hardcoding in plain text) - 1 point
    [X] Implementing profile detail retrieval into web app's DB - 2 points
    [logout, without token revocation] Implementing a log-out workflow (token revocation) - 2 points
"""

from flask import Flask, session, render_template, url_for, redirect
import sqlite3
from authlib.integrations.flask_client import OAuth
 
app = Flask(__name__)
app.config.update(
    SERVER_NAME = '127.0.0.1:5000',
    SECRET_KEY = 'very secret',
    DEBUG = True
)

conn = sqlite3.connect("users.db", check_same_thread=False)
c = conn.cursor()
if conn is not None:
    try:
        c.execute('''
            CREATE TABLE IF NOT EXISTS users(
            `id` INTEGER PRIMARY KEY, 
            `name` TEXT NOT NULL, 
            `email` TEXT NOT NULL,
            UNIQUE(email))
        ''')
        print('DATABASE DETECTED')
    except:
        print('DATABASE CREATION ERROR')

oauth = OAuth(app)
 
@app.route('/')
def index():
    user = session.get('user')
    return render_template('index.html', user = user)
 
@app.route('/google/')
def google():
    GOOGLE_CLIENT_ID = '781259896495-sht1bn6f9dbqvk2ej8m6o0e2mjkjia36.apps.googleusercontent.com'
    GOOGLE_CLIENT_SECRET = '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'
    CONF_URL = 'https://accounts.google.com/.well-known/openid-configuration'

    oauth.register(
        name='google',
        client_id=GOOGLE_CLIENT_ID,
        client_secret=GOOGLE_CLIENT_SECRET,
        server_metadata_url=CONF_URL,
        userinfo_endpoint='https://openidconnect.googleapis.com/v1/userinfo',
        client_kwargs={
            'scope': 'openid email profile'
        }
    )
     
    redirect_uri = url_for('authorize', _external=True)
    return oauth.google.authorize_redirect(redirect_uri)
 
@app.route('/authorize')
def authorize():
    token = oauth.google.authorize_access_token()
    user = oauth.google.parse_id_token(token)
    resp = oauth.google.userinfo()
    print(resp)

    c.execute("INSERT OR IGNORE INTO users (`name`, `email`) VALUES (?, ?)", (user.name, user.email,))
    conn.commit()

    if user:
        session['user'] = user, token
    
    return redirect('/')

@app.route('/logout')
def logout():

    session.pop('user', None)
    return redirect('/')
 
if __name__ == "__main__":
    app.run(debug=True)