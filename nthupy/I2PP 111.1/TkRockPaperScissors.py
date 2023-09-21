import tkinter as tk
import random

root = tk.Tk()
root.title("Rock, Paper, Scissors")
frame = tk.Frame(root)
frame.pack()

def play_game(choice):
  computer_choice = random.choice(["rock", "paper", "scissors"])
  your_hand_display.config(text=choice)
  if computer_choice == "rock":
    computer_hand_display.config(text="✊")
  elif computer_choice == "paper":
    computer_hand_display.config(text="✋")
  else:
    computer_hand_display.config(text="✌")
  
  if choice == computer_choice:
    status_display.config(text="Tied!")
  elif (choice == "rock" and computer_choice == "scissors") or (choice == "scissors" and computer_choice == "paper") or (choice == "paper" and computer_choice == "rock"):
    status_display.config(text="User wins!")
  else:
    status_display.config(text="Computer wins!")

def reset_game():
  your_hand_display.config(text="")
  computer_hand_display.config(text="")
  status_display.config(text="")

your_hand_label = tk.Label(frame, text="Your hand:").grid(row=0, column=0)
computer_hand_label = tk.Label(frame, text="Computer's hand:").grid(row=1, column=0)
status_label = tk.Label(frame, text="Status:").grid(row=2, column=0)

rock_button = tk.Button(frame, text="✊", command=lambda: play_game("rock")).grid(row=0, column=1)
paper_button = tk.Button(frame, text="✋", command=lambda: play_game("paper")).grid(row=0, column=2)
scissors_button = tk.Button(frame, text="✌", command=lambda: play_game("scissors")).grid(row=0, column=3)
retry_button = tk.Button(frame, text="Retry", command=reset_game).grid(row=2, column=1)
quit_button = tk.Button(frame, text="Quit", command=root.destroy).grid(row=2, column=2)

your_hand_display = tk.Label(frame, text="").grid(row=0, column=4)
computer_hand_display = tk.Label(frame, text="").grid(row=1, column=1)
status_display = tk.Label(frame, text="").grid(row=2, column=3)

root.mainloop()