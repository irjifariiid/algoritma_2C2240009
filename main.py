import re

somme_totale = 0

# Importation de la liste à analyser
with open('AOC_day1.txt', 'r') as f:
    for line in f:
        fdigit = re.search(r'\d', line)  # Expression régulière pour extraire le premier chiffre
        ldigit = re.search(r'(\d{1})(?!.*\d{1})', line)  # Expression régulière pour extraire le dernier chiffre

        # Obtention des valeurs de calibration
        if fdigit and ldigit:
            somme1 = fdigit.group()
            somme2 = ldigit.group()
            rmatch = int(somme1 + somme2)
            somme_totale += rmatch

print("La somme totale des valeurs de calibration est:", somme_totale)
