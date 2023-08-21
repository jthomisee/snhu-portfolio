package com.grandstrandsystems.contactservice;

import org.junit.jupiter.api.*;

public class ContactTest {

    @Test
    public void testContactId() {
        Contact contact = new Contact("1", "John", "Doe", "1234567890", "123 Street");
        Assertions.assertEquals("1", contact.getId());
    }

    @Test
    public void testContactFirstName() {
        Contact contact = new Contact("1", "John", "Doe", "1234567890", "123 Street");
        Assertions.assertEquals("John", contact.getFirstName());
    }

    @Test
    public void testContactLastName() {
        Contact contact = new Contact("1", "John", "Doe", "1234567890", "123 Street");
        Assertions.assertEquals("Doe", contact.getLastName());
    }

    @Test
    public void testContactPhone() {
        Contact contact = new Contact("1", "John", "Doe", "1234567890", "123 Street");
        Assertions.assertEquals("1234567890", contact.getPhone());
    }

    @Test
    public void testContactAddress() {
        Contact contact = new Contact("1", "John", "Doe", "1234567890", "123 Street");
        Assertions.assertEquals("123 Street", contact.getAddress());
    }
}
