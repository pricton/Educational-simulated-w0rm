# 🧪 Educational Worm Simulation – Self-Replication Demo (C++)

> ⚠️ This project is for **educational and research purposes only**.  
> It simulates the behavior of a self-replicating program in a safe, controlled, and non-malicious way.

---

## 📄 Description

This program demonstrates a basic simulation of worm-like behavior: **self-replication**.  
It copies its own executable under a **randomized new filename** (e.g., `copy_x8kz4v.exe`) within the same directory.

🚫 **Note:**  
- No network activity  
- No payload or harm  
- No persistence  
- No spreading beyond the local directory

The goal is to help students and researchers understand how basic self-replicating logic works — safely and ethically.

---

## 🔧 How It Works

### Main Components:
- `generateRandomName()`  
  Creates a randomized filename using lowercase letters and digits (e.g. `copy_1a2b3c.exe`).

- `replicateSelf()`  
  Reads the current executable path using `/proc/self/exe` (Linux only), and copies the file under a new random name in the same directory.

- `main()`  
  Launches the replication simulation and prints status messages.

---

## ✅ Example Output

```bash
mini-worm started.
copy created: copy_k4z3g9.exe
