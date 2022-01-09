import json

plants = []

with open('plants.json') as jf:
    data = json.load(jf)
    
    for i, plant in enumerate(data['data']):
        plants.append(plant[10].rstrip(' ').replace(' ', '_') + '\n')

    plants = sorted(plants)

    with open('files\\ulazni.txt', 'w') as fp:
        fp.writelines(plants)

for i in range(3):
    with open('files\\vrste' + str((i + 2) % 3 + 1) + '.txt', 'w') as fp:
        for j in range(i*56, (i + 1) * 56 - 1):
            fp.write(plants[j])

