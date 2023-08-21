# Artemis Financial Software Security Enhancement - README

## Client Summary

**Client**: Artemis Financial  
**Requirements**: Artemis Financial is a consulting firm specializing in individualized financial plans, including savings, retirement, investments, and insurance. They sought to modernize their operations with a focus on enhancing software security. Specifically, they wanted to add a file verification step in their web application to ensure secure communications via checksums.

## Achievements in Identifying Security Vulnerabilities

I performed a comprehensive vulnerability assessment on the existing codebase. I identified areas that were susceptible to data tampering and man-in-the-middle attacks. Secure coding is not just a best practice; it's a necessity. It safeguards a company's data, maintains customer trust, and ensures operational continuity. For Artemis Financial, this is especially crucial given the sensitive nature of financial data they handle.

## Challenges and Learnings in Vulnerability Assessment

The most challenging part was ensuring that the newly added security layers did not introduce new vulnerabilities. This required a deep understanding of both the existing code and the security features being implemented. The process was educational as it provided insights into real-world applications of cryptographic algorithms and secure data transmission techniques.

## Increasing Layers of Security

I implemented several layers of security:

1. **Data Verification**: Introduced SHA-256 checksums for data integrity.
2. **Encrypted Communication**: Transitioned from HTTP to HTTPS.
3. **Certificate Authentication**: Generated self-signed certificates for secure communication during development.

For future assessments, I would consider using tools like OWASP ZAP for dynamic analysis and SonarQube for static code analysis to identify vulnerabilities and decide on mitigation techniques.

## Ensuring Functionality and Security

After refactoring the code, I ran multiple tests to ensure that the application was both functional and secure. I used OWASP Dependency-Check Maven to ensure that the new code did not introduce additional vulnerabilities. I also manually reviewed the code to identify any syntactical, logical, or security issues.

## Resources and Tools for Future Assignments

- **Spring Security**: For robust security configurations.
- **Java Cryptography Extension (JCE)**: For cryptographic operations.
- **OWASP Dependency-Check Maven**: For identifying known vulnerabilities in dependencies.

## Showcasing Skills to Future Employers

From this assignment, I would showcase:

1. **Vulnerability Assessment Report**: Demonstrates my ability to identify and understand security vulnerabilities.
2. **Refactored Code**: Highlights my skills in secure coding practices.
3. **Documentation**: The README and inline comments can serve as an example of my attention to detail and my ability to document complex processes clearly and concisely.

By successfully enhancing the security features of Artemis Financial's software, I've gained invaluable experience that makes me a strong candidate for roles requiring expertise in secure software development.
