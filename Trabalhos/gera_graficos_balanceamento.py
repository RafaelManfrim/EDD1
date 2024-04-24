import matplotlib.pyplot as plt
from collections import Counter


def plot_string_occurrences(file_path, num_players):
    with open(file_path, 'r') as file:
        lines = file.readlines()
        string_counter = Counter(lines)

    strings = list(string_counter.keys())
    occurrences = list(string_counter.values())

    plt.figure(figsize=(10, 6))
    plt.bar(strings, occurrences, color='skyblue')
    plt.xlabel('Classes')
    plt.ylabel('Vitórias')
    plt.title(f'Vitórias por classe ({num_players} jogadores)')
    plt.savefig(f'/home/manfrim/Documentos/Facul/EDD1/Trabalhos/{num_players}.png')
    plt.show()


file_path = '/home/manfrim/Documentos/Facul/EDD1/8.txt'
plot_string_occurrences(file_path, 8)
file_path = '/home/manfrim/Documentos/Facul/EDD1/16.txt'
plot_string_occurrences(file_path, 16)
file_path = '/home/manfrim/Documentos/Facul/EDD1/32.txt'
plot_string_occurrences(file_path, 32)
