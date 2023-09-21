import torch
from diffusers import StableDiffusionPipeline

pipe = StableDiffusionPipeline.from_pretrained("nitrosocke/Ghibli-Diffusion", torch_dtype=torch.float16)
pipe = pipe.to("cuda")

prompt = "a girl with a book and an apple"
image = pipe(prompt).images[0]
image.show()