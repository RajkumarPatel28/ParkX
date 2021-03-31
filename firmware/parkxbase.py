import pyrebase
import serial
import time

config = {
  "apiKey": "apiKey",
  "authDomain": "projectId.firebaseapp.com",
  "databaseURL": "https://databaseName.firebaseio.com",
  "storageBucket": "projectId.appspot.com"
}

firebase = pyrebase.initialize_app(config)
db = firebase.database()

ser = serial.Serial("/dev/ttyACM0", 2400)
time.sleep(0.2) # Allow serial connection to establish
sensor = False # True for sensor, False for effectors

spots = int(db.child("spots").get().val())

if ser.isOpen():
	ser.write(str(spots).encode('ascii'))
	
	while True:
		if (sensor == True):
			ultrasonic_data = ser.readline()
			db.child("distance").set(ultrasonic_data.decode("utf-8"))

		else:
			distance = float(db.child("distance").get().val())

			while (distance >= 3 and distance <= 5): # Entry
				distance = float(db.child("distance").get().val())
				buzzer = db.child("buzzer").get().val()
				db.child("vehicle").set("true")
				ser.write(b'o')
				ser.write(b's')

				if (buzzer == 'true'):
					ser.write(b'h')

				if (distance >= 11): # Vehicle has passed
					db.child("vehicle").set("false")
					ser.write(b'c')
					
					if (spots != 0):					
						spots -= 1
						ser.write(str(spots).encode('ascii'))
						db.child("spots").set(spots)

					else:
						spots = 0
					 
			while (distance >= 7 and distance <= 9): # Exit
				distance = float(db.child("distance").get().val())
				buzzer = db.child("buzzer").get().val()
				db.child("vehicle").set("true")
				ser.write(b's')

				if (buzzer == 'true'):
					ser.write(b'h')

				if (distance >= 11): # Vehicle has passed
					db.child("vehicle").set("false")

					if (spots != 9):
						spots += 1
						ser.write(str(spots).encode('ascii'))
						db.child("spots").set(spots)

					else:
						spots = 9

else: # Entry and exit empty
	ser.write(b'c')
