import pandas as pd

def getDataframeSize(players):
    rows = len(players)
    cols = len(players.columns)
    return [rows, cols]