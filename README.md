# Simulation of Fast Food Restaurant

This project is a simulation of a fast food restaurant using multi-threading in C++. The simulation is based on the concept of an ice cream factory problem, where customers enter the restaurant, place their orders, and receive their dishes through a kitchen and server system.

## Problem Description
The simulation aims to replicate the operations of a fast food restaurant. Customers enter the restaurant, select items from the menu, specify quantities, and make payments. The orders are then processed by the kitchen staff and served by the servers. The simulation keeps track of daily sales and daily waiter sales.

## Implementation Details
The implementation uses various synchronization primitives like semaphores to coordinate the actions of customers, kitchen staff, and servers. Here's an overview of the components and their roles:

1. **Customers**: Represented by individual threads, customers enter the restaurant, place orders, and make payments. Each customer thread is responsible for interacting with the user to select items from the menu, specify quantities, and calculate the total amount.

2. **Kitchen**: Modeled using three cook semaphores, the kitchen processes the orders placed by customers. The kitchen simulates the time required to prepare the dishes based on the quantities of different items ordered by customers.

3. **Servers**: Servers are represented by five waiter semaphores. They receive the prepared dishes from the kitchen and serve them to the respective customers.

4. **Synchronization Primitives**: Entry, order_p, order_r, and bill semaphores are used to control the flow of customers, orders, and payments. These semaphores ensure that customers enter the restaurant one at a time, orders are processed and served sequentially, and payments are made without conflicts.

## Running the Simulation
To execute the simulation of the Fast Food Restaurant on the terminal, follow these steps:

1. Open a terminal window.

2. Navigate to the directory where the source code file is located using the `cd` command. For example, if the file is located in the "Documents" directory, use the following command:
   ```
   cd Documents
   ```

3. Compile the source code using a C++ compiler. Use the following command:
   ```
   g++ -pthread fast_food_simulation.cpp -o fast_food_simulation
   ```

4. After successful compilation, an executable file named `fast_food_simulation` will be created in the same directory.

5. Run the simulation by executing the generated executable. Use the following command:
   ```
   ./fast_food_simulation
   ```

6. The program will prompt you to enter the total number of customers for the simulation. Provide the desired number and press Enter.

7. The simulation will start, and you will see the progress and output of the simulation in the terminal.

8. Once the simulation is complete, the daily sales and daily waiter sales will be displayed.

9. You can run the simulation multiple times by repeating steps 5-8.

Note: Make sure you have a C++ compiler installed on your system, such as `g++`, and that you have the necessary permissions to compile and execute the code.

## Repository Information
This repository contains the source code for the simulation of a fast food restaurant. The project is inspired by the ice cream factory problem but focuses on the broader concept of a fast food restaurant. The code is written in C++ and utilizes multi-threading and synchronization primitives.

## Acknowledgments
The simulation is based on the ice cream factory problem and is implemented as a standalone project. The original problem statement and related materials can be found in various computer science textbooks and online resources. This project is intended for educational purposes to demonstrate multi-threading and synchronization concepts in a practical scenario.

Please note that this simulation may not cover all aspects and intricacies of a real-world fast food restaurant. It simplifies the operations for the purpose of demonstration and learning.
