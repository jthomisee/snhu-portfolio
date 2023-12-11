from pymongo import MongoClient

class AnimalShelter:
    def __init__(self, db_name, collection_name, username, password, host, port):
        self.client = MongoClient(f"mongodb://{username}:{password}@{host}:{port}")
        self.db = self.client[db_name]
        self.collection = self.db[collection_name]

    def create(self, data):
        """
        Inserts a document into the collection.
        :param data: The document to insert.
        :return: True if successful, else False.
        """
        try:
            self.collection.insert_one(data)
            return True
        except Exception as e:
            print(f"An error occurred: {e}")
            return False

    def read(self, query):
        """
        Queries for documents in the collection.
        :param query: The query parameters.
        :return: List of documents if successful, else an empty list.
        """
        try:
            return list(self.collection.find(query))
        except Exception as e:
            print(f"An error occurred: {e}")
            return []

    def update(self, query, new_values):
        """
        Updates documents in the collection.
        :param query: The query parameters to find the documents.
        :param new_values: The new values to update.
        :return: Number of documents updated.
        """
        try:
            update_result = self.collection.update_many(query, {'$set': new_values})
            return update_result.modified_count
        except Exception as e:
            print(f"An error occurred: {e}")
            return 0

    def delete(self, query):
        """
        Deletes documents from the collection.
        :param query: The query parameters to find the documents.
        :return: Number of documents deleted.
        """
        try:
            delete_result = self.collection.delete_many(query)
            return delete_result.deleted_count
        except Exception as e:
            print(f"An error occurred: {e}")
            return 0

    def water_rescue_query(self):
        query = {
            'breed': {'$in': ['Labrador Retriever Mix', 'Chesapeake Bay Retriever', 'Newfoundland']},
            'sex_upon_outcome': 'Intact Female',
            'age_upon_outcome_in_weeks': {'$gte': 26, '$lte': 156}
        }
        return self.read(query)

    def mountain_rescue_query(self):
        query = {
            'breed': {'$in': ['German Shepherd', 'Alaskan Malamute', 'Old English Sheepdog', 'Siberian Husky', 'Rottweiler']},
            'sex_upon_outcome': 'Intact Male',
            'age_upon_outcome_in_weeks': {'$gte': 26, '$lte': 156}
        }
        return self.read(query)

    def disaster_tracking_query(self):
        query = {
            'breed': {'$in': ['Doberman Pinscher', 'German Shepherd', 'Golden Retriever', 'Bloodhound', 'Rottweiler']},
            'sex_upon_outcome': 'Intact Male',
            'age_upon_outcome_in_weeks': {'$gte': 20, '$lte': 300}
        }
        return self.read(query)

