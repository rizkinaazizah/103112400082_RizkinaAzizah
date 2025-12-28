import pandas as pd
import matplotlib.pyplot as plt

# Membaca file CSV hasil dari C++ tadi
data = pd.read_csv('data_modulus.csv')

# Plotting
plt.plot(data['N'], data['Iteratif'], label='Iteratif', marker='o')
plt.plot(data['N'], data['Rekursif'], label='Rekursif', marker='s')

plt.title('Perbandingan Waktu Eksekusi Modulus')
plt.xlabel('Ukuran Input (N)')
plt.ylabel('Waktu (ms)')
plt.legend()
plt.grid(True)
plt.show()