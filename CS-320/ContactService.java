package com.grandstrandsystems.contactservice;

import java.util.*;

public class ContactService {
    private Map<String, Contact> contacts = new HashMap<>();

    public void addContact(Contact contact) {
        if (contacts.containsKey(contact.getId())) {
            throw new IllegalArgumentException("Contact ID already exists");
        }
        contacts.put(contact.getId(), contact);
    }

    public Contact getContact(String id) {
        return contacts.get(id);
    }

    public void deleteContact(String id) {
        contacts.remove(id);
    }

    public void updateContact(String id, String firstName, String lastName, String phone, String address) {
        Contact contact = contacts.get(id);
        if (contact != null) {
            contact.setFirstName(firstName);
            contact.setLastName(lastName);
            contact.setPhone(phone);
            contact.setAddress(address);
        }
    }
}
