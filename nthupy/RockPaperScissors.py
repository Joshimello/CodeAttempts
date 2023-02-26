import random

print("rock, paper, scissors?")

while True:
    user_choice = input()
    if user_choice == "quit":
        print("bye")
        break
    
    choices = ["rock", "paper", "scissors"]
    if user_choice not in choices:
        print(f"{user_choice} is invalid - try again?")
        continue
    
    computer_choice = random.choice(choices)

    if user_choice == computer_choice:
        print(f"I am also {computer_choice} - tied!")
    elif user_choice == "rock" and computer_choice == "scissors":
        print(f"I am {computer_choice} - you win!")
    elif user_choice == "paper" and computer_choice == "rock":
        print(f"I am {computer_choice} - you win!")
    elif user_choice == "scissors" and computer_choice == "paper":
        print(f"I am {computer_choice} - you win!")
    else:
        print(f"I am {computer_choice} - I win!")