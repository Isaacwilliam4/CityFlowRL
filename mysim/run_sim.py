import cityflow
from tqdm import tqdm
eng = cityflow.Engine('/home/isaacpeterson/research/repos/CityFlowRL/mysim/config.json', roadtype="graph", thread_num=1)

for _ in tqdm(range(1000)):
  eng.next_step()