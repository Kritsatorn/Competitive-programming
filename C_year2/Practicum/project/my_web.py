from my_project import find_mcu_boards, McuBoard, PeriBoard
from flask import Flask, render_template, redirect, url_for
 
devices = find_mcu_boards()
mcu = McuBoard(devices[0])
peri = PeriBoard(mcu)
app = Flask(__name__)
count = 0
@app.route("/")
def index():

   light1 = peri.get_light1()
   light2 = peri.get_light2()
   succes = ""
#  acticvate motor
   if ( light1 <= 500 ) :
     if ( count % 2 == 0) :
      set_work(2,1)
     else :
      set_work(2,0)
   count += 1
   if ( light2 <= 700):
     succes = "Congrate !! you win "

   return """
     <h1>Practicum Demo</h1>
     <div>
       Light1 status: {}
     </div>
     <div>
       Light2 status: {}
     </div>
     <div>
       MOTOR control:
       <ul>
        <li>laser1: <a href="/work/0/0">OFF</a> | <a href="/work/0/1">ON</a></li>
        <li>laser2: <a href="/work/1/0">OFF</a> | <a href="/work/1/1">ON</a></li>
         <li>MOTOR: <a href="/work/2/0">OFF</a> | <a href="/work/2/1">ON</a></li>
       </ul>
       <div> {} </div>
     </div>
   """.format(light1,light2,succes)
@app.route("/work/<int:no>/<int:state>")
def set_work(no,state):
   peri.set_work(no,state)
   return redirect(url_for("index"))

app.run(debug=True, port=8000, host="0.0.0.0")