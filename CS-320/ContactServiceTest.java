package com.grandstrandsystems.contactservice;

import org.junit.jupiter.api.*;

public class ContactServiceTest {

    @Test
    public void testAddContact() {
        ContactService service = new ContactService();
        service.addContact(new Contact("1", "John", "Doe", "1234567890", "123 Street"));
        Contact retrievedContact = service.getContact("1");
        Assertions.assertEquals("1", retrievedContact.getId());
        Assertions.assertEquals("John", retrievedContact.getFirstName());
        Assertions.assertEquals("Doe", retrievedContact.getLastName());
        Assertions.assertEquals("1234567890", retrievedContact.getPhone());
        Assertions.assertEquals("123 Street", retrievedContact.getAddress());
    }

    @Test
    public void testAddContactWithExistingId() {
        ContactService service = new ContactService();
        service.addContact(new Contact("1", "John", "Doe", "1234567890", "123 Street"));
        Assertions.assertThrows(IllegalArgumentException.class, () -> service.addContact(new Contact("1", "Jane", "Doe", "0987654321", "321 Street")));
    }

    @Test
    public void testUpdateContact() {
        ContactService service = new ContactService();
        service.addContact(new Contact("1", "John", "Doe", "1234567890", "123 Street"));
        service.updateContact("1", "Jane", "Doe", "0987654321", "321 Street");
        Contact updatedContact = service.getContact("1");
        Assertions.assertEquals("Jane", updatedContact.getFirstName());
        Assertions.assertEquals("Doe", updatedContact.getLastName());
        Assertions.assertEquals("0987654321", updatedContact.getPhone());
        Assertions.assertEquals("321 Street", updatedContact.getAddress());
    }

    @Test
    public void testDeleteContact() {
        ContactService service = new ContactService();
        service.addContact(new Contact("1", "John", "Doe", "1234567890", "123 Street"));
        service.deleteContact("1");
        Assertions.assertNull(service.getContact("1"));
    }
}
