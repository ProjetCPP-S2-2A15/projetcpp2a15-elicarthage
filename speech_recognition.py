import sys
import speech_recognition as sr
import logging

logging.basicConfig(level=logging.INFO)

def recognize_speech():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("ECOUTE...", file=sys.stderr)
        r.energy_threshold = 4000
        r.dynamic_energy_threshold = True
        r.adjust_for_ambient_noise(source, duration=1)

        try:
            audio = r.listen(source, timeout=5, phrase_time_limit=3)
            text = r.recognize_google(audio, language='fr-FR')
            print(text)
            return text
        except sr.UnknownValueError:
            print("ERREUR: Impossible de comprendre l'audio", file=sys.stderr)
        except sr.RequestError as e:
            print(f"ERREUR_API: {e}", file=sys.stderr)
        except Exception as e:
            print(f"ERREUR: {str(e)}", file=sys.stderr)
    return ""

if __name__ == "__main__":
    recognize_speech()
