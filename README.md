# Kyuubi
A 3x3 Rubik's Cube Solver
<br>
<h3>What is Kyuubi?</h3>
Kyuubi is a 3x3 Rubik's Cube Solving Guide which helps the user to solve the Rubik's Cube by inspecting the faces of the cube and then advising the user a set of moves which will result in a fully solved cube.<br>
<b>NOTE</b> - Kyuubi is currently evolving into a fully functional robot which will be able to solve the cube on its own!
<br><br>

<h3>Requirements - </h3>
<ol>
<li>Python</li>
<li>Opencv library in Python</li>
<li>g++</li>
</ol>
<br>
<h3>Installation Procedure - </h3>
<ol>
<li>Download Kyuubi by clicking <a href="https://github.com/kipawa/Kyuubi/archive/master.zip">here</a></li>
<li>Extract the downloaded zip file to the Desktop (i.e Kyuubi-master should be at your Desktop) </li>
<li>Open the terminal and execute the following commands in specified order -
    <ul>
    <li>cd ~/Desktop/Kyuubi-master</li>
    <li>python Train.py<br>
        <ul>
        <li>Your webcam will open showing a 3x3 Grid, now you have to train the program by showing it all the six solved faces of cube.</li>
        <li>To show a face just take the cube so that the colors get filled into the 3x3 grid and then hit the "space" button </li>
        <li>Show the blue face first, followed by Red, Yellow, Orange, White and Green in the specified order</li>
        <li>The program will stop the moment you have fed all the six faces to it (Make sure you follow the order of colors)</li>
        </ul>
    </li>
    <li>python read.py<br>
        <ul>
        <li>The webcam will open showing the same 3x3 grid but as soon as you place your cube in front of it, It will suggest the color of each cubie detected by it.</li>
        <li>Now Scramble the cube</li>
        <li>Now Keep the Red face on front so that Blue face becomes top</li>
        <li>Now feed the program with the scrambled faces in the following order - Blue, Red, Yellow, Orange, White, Green</li>
        <li>To feed the face just take the face in front of the grid and when you feel that all detected colors are correct, just hit the "space" button</li>
        <li>The program will end when you have fed all the six faces to it</li>
        </ul>
    </li>
    <li>cd Algorithm</li>
    <li>g++ layer3.cpp</li>
    <li>./a.out < inp </li>
    <li>cat out.txt </li>
    <li>You will have a set of moves to solve the cube. To read about the moves please read "Moves.txt"</li>
    </ul>
    
<h3>Owners - </h3>
The project is owned by - <br>
<b>1. <a href="https://github.com/kipawa">Aditya Shankar Tripathi</a></b><br>
<b>2. <a href="https://github.com/mmmaks">Manish Kumar Sinha</a></b><br>

<h3>Request to User</h3>
For any bugs, just drop a mail at megatron6496@gmail.com
