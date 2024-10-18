# Define the number of elements
num_elements = 100000000

# Open the file in write mode
with open("random.txt", "w") as file:
    # Write integers in decreasing order
    for i in range(num_elements, 0, -1):
        file.write(f"{i}\n")

print(f"{num_elements} elements have been written to 'random.txt'.")
