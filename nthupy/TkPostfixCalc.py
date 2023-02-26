import datetime

# stack to store and manipulate dates
stack = []

# function to get current date
def today():
    return datetime.date.today()

# function to add or subtract days from a date
def date_calc(op, date, days):
    if op == "add":
        return date + datetime.timedelta(days=days)
    elif op == "sub":
        return date - datetime.timedelta(days=days)

# Tkinter GUI
import tkinter as tk

def push():
    # get value from Entry widget and try to evaluate it
    try:
        value = eval(entry.get())
        stack.append(value)
        entry.delete(0, "end")
        update_listbox()
    except Exception as e:
        error_label.config(text=f"Error: {e}")

def update_listbox():
    listbox.delete(0, "end")
    for item in stack[::-1]:
        listbox.insert("end", item)

def clear():
    stack.clear()
    update_listbox()

def swap():
    if len(stack) >= 2:
        stack[-1], stack[-2] = stack[-2], stack[-1]
        update_listbox()

def quit():
    root.destroy()

root = tk.Tk()

# left pane with buttons and Entry widget
left_frame = tk.Frame(root)
left_frame.pack(side="left")

# today, tomorrow, and yesterday buttons
today_button = tk.Button(left_frame, text="Today", command=today)
today_button.pack()

tomorrow_button = tk.Button(left_frame, text="Tomorrow", command=lambda: stack.append(date_calc("add", stack.pop(), 1)))
tomorrow_button.pack()

yesterday_button = tk.Button(left_frame, text="Yesterday", command=lambda: stack.append(date_calc("sub", stack.pop(), 1)))
yesterday_button.pack()

# add and sub buttons
add_button = tk.Button(left_frame, text="Add", command=lambda: stack.append(date_calc("add", stack.pop(), stack.pop())))
add_button.pack()

sub_button = tk.Button(left_frame, text="Sub", command=lambda: stack.append(date_calc("sub", stack.pop(), stack.pop())))
sub_button.pack()

# swap button
swap_button = tk.Button(left_frame, text="Swap", command=swap)
swap_button.pack()

# push button
push_button = tk.Button(left_frame, text="Push", command=push)
push_button.pack()

# Entry widget and error label
entry = tk.Entry(left_frame)
entry.pack()
error_label = tk.Label(left_frame, text="")
error_label.pack()

# right pane with ListBox
right_frame = tk.Frame(root)
right_frame.pack(side="right")

listbox = tk.Listbox(right_frame)
listbox.pack()

# Clear and Quit buttons
clear_button = tk.Button(right_frame, text="Clear", command=clear)
clear_button.pack()

quit_button = tk.Button(right_frame, text="Quit", command=quit)
quit_button.pack()

root.mainloop()