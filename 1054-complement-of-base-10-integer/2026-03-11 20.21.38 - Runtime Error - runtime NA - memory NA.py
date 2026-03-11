def generate_summary(title, text):
    combined = f"{title}. {text}"

    sentences = combined.split(".")
    summary = ". ".join(sentences[:2])

    return summary[:300]