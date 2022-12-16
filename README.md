# ProjectOne-Clock

**Summarize the project and what problem it was solving.**

The goal of the project was to write a program in C++ that would display a clock in both 12 and 24 hour formats to the screen. It should also allow the user to add seconds, minutes, and hours to the current time.

**What did you do particularly well?**

I think I wrote the code in a very easy to read way and made sure that the code would behave correctly when second, minutes, or hours went above 59. For example if you add a second to 1:59:59PM, it will set the seconds to 00 and increase the minutes and hours by 1.

**Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?**

I could enhance the code by writing a GUI to make it a little more user friendly. 

**Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?**

The most challenging part of the code was trying to think of all of the ways a user may interact with it and making sure I was prepared for it. An example of this is what to do if the user increases the minutes when it is already at 59 minutes.

**What skills from this project will be particularly transferable to other projects or course work?**

This was my first C++ project, so I will be able to refer back to this for some of the basics in my future work.

**How did you make this program maintainable, readable, and adaptable?**

I made this program maintainable, readable, and adaptable by seperating the code into different functions. Adding time, getting user input, printing the menu, and printing the time are all in their own functions.