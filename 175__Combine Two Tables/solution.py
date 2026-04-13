import pandas as pd

def combine_two_tables(person, address):
    return person.merge(address, on="personId", how="left")[["firstName", "lastName", "city", "state"]]

    