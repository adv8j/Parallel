contents = [
    
 
]

# Writing each test case into separate files
for idx, content in enumerate(contents, start=1):
    filename = f"input/{idx}_wrong.txt"
    with open(filename, "w") as file:
        file.write(content)
