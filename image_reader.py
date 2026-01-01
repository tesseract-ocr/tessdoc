import pytesseract
from PIL import Image

pytesseract.pytesseract.tesseract_cmd = r"C:\Program Files\Tesseract-OCR\tesseract.exe"

def read_dimensions(image_path):
    text = pytesseract.image_to_string(Image.open(image_path))
    numbers = [int(s) for s in text.split() if s.isdigit()]
    return numbers

print(read_dimensions("sketch.jpg"))
