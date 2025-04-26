import threading
import requests

def send_request():
    requests.get("https://courses.it4all.vn/")

if __name__ == "__main__":
    n = int(input("Nhập số luồng: "))  # Người dùng nhập số luồng
    threads = []
    
    for _ in range(n):
        thread = threading.Thread(target=send_request)
        thread.start()
        threads.append(thread)
      

        print("...")
    
    for thread in threads:
        thread.join()
