# CS-465 Project README

## Architecture

### Frontend Development Comparison
In my full stack project, I leveraged multiple frontend technologies including Express HTML, JavaScript, and the Angular framework for creating a Single Page Application (SPA). 

- **Express HTML** served as a straightforward method to serve static pages and forms. It is simple but less dynamic.
- **JavaScript** was used to add interactivity to web pages. It's essential for client-side scripting and AJAX calls for asynchronous web page updates.
- **Single Page Application (SPA)**, developed using Angular, offers a more fluid user experience, reducing the need for page reloads. This approach allows for a more app-like experience, with data being dynamically loaded and displayed on the same page.

The contrast lies in the complexity and user experience. Express HTML and JavaScript are fundamental for any web development, but SPAs represent a more advanced approach, enabling highly interactive web applications.

### Backend: Use of NoSQL MongoDB
I used a NoSQL MongoDB database for the backend due to its flexibility with schema design, scalability, and its efficient handling of large volumes of unstructured data. This choice supports the dynamic nature of travel booking information, allowing for rapid development and iteration.

## Functionality

### JSON and JavaScript
JSON is a lightweight data-interchange format that is easy for humans to read and write and for machines to parse and generate. Despite its name, JSON is language-independent. It ties together the frontend and backend by serving as a universal format for exchanging data. Unlike JavaScript, which is a full programming language, JSON is purely a data format. In my project, JSON played a crucial role in transferring data between the server and the client, enabling dynamic content updates without page reloads.

### Refactoring and UI Components
Throughout the development process, I refactored code to enhance functionality and efficiency. For instance, I modularized repetitive UI elements into reusable Angular components, significantly speeding up development time and ensuring UI consistency. This approach also simplified future updates and maintenance.

## Testing

### API Testing and Security
Testing the API involved multiple methods to ensure the request and retrieval of data worked as expected, particularly focusing on:

- **Endpoint testing** to verify that each API endpoint responds correctly to the expected HTTP requests.
- **Security testing** to ensure that added security layers, such as authentication tokens and data encryption, do not interfere with the API's functionality.

The complexity of testing increased with the implementation of security measures, requiring us to adopt strategies such as token-based authentication testing.

## Reflection

This course has significantly advanced my professional development by equipping me with practical skills in full stack web development. I've learned to design and implement the architecture of web applications, utilize frameworks for both frontend and backend development, and integrate databases using modern technologies. These skills not only make me a more competent developer but also enhance my marketability in the tech industry.
