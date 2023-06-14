import os

folder_path = r"D:/OneDrive - Bansilal Ramnath Agarwal Charitable Trust, Vishwakarma Institute's/Coding/DSA/Trees"  # Replace with the actual folder path

# Get a list of all .cpp files in the folder
cpp_files = [f for f in os.listdir(folder_path) if os.path.isfile(os.path.join(folder_path, f)) and f.endswith(".c++")]

# Iterate over each .cpp file
for file_name in cpp_files:
    file_path = os.path.join(folder_path, file_name)
    new_file_name = file_name[:-2] + 'pp'

    # Rename the file
    new_file_path = os.path.join(folder_path, new_file_name)
    os.rename(file_path, new_file_path)

    print(f"Renamed {file_name} to {new_file_name}")
