import re

origin = input()[6:-7].strip()

answer = re.sub(r'<div title="([\w]*)">', lambda x : f"title : {x.group(1)}", origin)
answer = answer.replace("<p>", "\n")
answer = answer.replace("</p>", "")
answer = answer.replace("</div>", "\n")
answer = re.sub(r"</*[a-z]*\s*>", '', answer)
answer = "\n".join(map(lambda x : x.strip(), answer.split('\n')))
answer = re.sub(r"\s{2,}", " ", answer)
answer.strip()
print(answer)