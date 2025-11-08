import pyttsx3

male = 0
female = 1

class Assistant:
    def __init__(self, gender=female, rate=123, volume=1.0, name="Athomycal", img=""):
        self.engine = pyttsx3.init()
