from wordcloud import WordCloud
import matplotlib.pyplot as plt

wordcloud = WordCloud().generate("ChatGPT[a] is an artificial intelligence (AI) chatbot developed by OpenAI and released in November 2022. It is built on top of OpenAI's GPT-3.5 and GPT-4 foundational large language models (LLMs) and has been fine-tuned (an approach to transfer learning) using both supervised and reinforcement learning techniques.ChatGPT launched as a prototype on November 30, 2022, and garnered attention for its detailed responses and articulate answers across many domains of knowledge.[3] Its propensity to confidently provide factually incorrect responses has been identified as a significant drawback.[4] In 2023, following the release of ChatGPT, OpenAI's valuation was estimated at US$29 billion.[5] The advent of the chatbot has increased competition within the space, accelerating the release of Google's Bard and Meta's LLaMA.The original release of ChatGPT was based on GPT-3.5. A version based on GPT-4, the newest OpenAI model, was released on March 14, 2023, and is available for paid subscribers on a limited basis.ChatGPT and GPT-4 have led computer scientists such as Geoffrey Hinton and Yoshua Bengio to voice concerns, including that future AI systems may surpass human intelligence, pursue misaligned goals, and pose existential risks.[6][7]")

# 繪圖
plt.figure()
plt.imshow(wordcloud, interpolation="bilinear")
plt.axis("off")
plt.show()