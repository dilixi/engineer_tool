import subprocess

def run_make():
    try:
        # Run the make command
        print("Running make...")
        subprocess.run(["make"], check=True)
        print("make completed successfully.")
    except subprocess.CalledProcessError as e:
        print(f"make failed with error: {e}")
        return False
    return True

def run_node_server():
    try:
        # Run the Node.js server
        print("Starting Node.js server...")
        subprocess.run(["node", "../server.js"], check=True)
        print("Node.js server started successfully.")
    except subprocess.CalledProcessError as e:
        print(f"Node.js server failed to start: {e}")
        return False
    return True

if __name__ == "__main__":
    if run_make():
        run_node_server()
