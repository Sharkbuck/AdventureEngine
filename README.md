-----ADVENTURE ENGINE-----
Author: Kyle Michel

Description:
  The Adventure Engine project was inspired by a class assignment in which I was asked to write a text-based
adventure game in C++. The code was messy, hard to read, and overall extremely hard to edit because of the
varying content that needed to be added. The Adventure Engine project is my answer to this problem, by
creating an XML format in which content can be added and subtracted and an underlying engine that
processes input and compares it to the content.

  I am using tinyxml-2 to help with xml parsing, all credit goes to the contributors to that project,
check out the source code here:
https://github.com/leethomason/tinyxml2
  
Status -- As of January 21, 2015:
The basic premise of xml file io has been demonstrated with the list of commands and their synonyms. At this
point, I am working on parsing user input grammar into valid command words and structures that can be
understood by the machine.
In the meantime, I'm adding another contributor to the project, who will start work on the Event class,
that will contain a generalized structure of any interaction that happens in the game.
