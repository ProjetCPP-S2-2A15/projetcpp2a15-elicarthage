# speech_recognition.py
import speech_recognition as sr
import sys

recognizer = sr.Recognizer()

with sr.Microphone() as source:
    print("Parlez...")
    audio = recognizer.listen(source)

try:
    text = recognizer.recognize_google(audio, language="fr-FR")
    print(text)
except sr.UnknownValueError:
    print("")
except sr.RequestError:
    print("")
