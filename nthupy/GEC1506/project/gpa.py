import os, sys, bisect, pickle, statistics

CLEARCMD = 'cls' #vscode change to 'clear'

benchmark_percentage = [0, 50, 60, 63, 67, 70, 73, 77, 80, 85, 90] 
benchmark_gpa = [0.0, 1.0, 1.7, 2.0, 2.3, 2.7, 3.0, 3.3, 3.7, 4.0, 4.3]
benchmark_letter = ['F', 'D', 'C-', 'C', 'C+', 'B-', 'B', 'B+', 'A-', 'A', 'A+']

class Course:
  def __init__(self, name, credits, weights):
    self.name = name
    self.credits = credits
    self.weights = weights
    self.scores = dict.fromkeys(weights, None)
    self.goal = 60

  @property
  def grades(self):
    percentage_grade = sum([v * self.weights[k] / 100 for k, v in self.scores.items() if v != None])
    grade_position = bisect.bisect_right(benchmark_percentage, percentage_grade)
    letter_grade = benchmark_letter[grade_position - 1]
    gpa_grade = benchmark_gpa[grade_position - 1]
    return percentage_grade, letter_grade, gpa_grade

  @property
  def passing(self):
    percentage_grade = sum([v * self.weights[k] / 100 for k, v in self.scores.items() if v != None])
    none_weights = sum([self.weights[k] for k, v in self.scores.items() if v == None])
    if none_weights > 0:
      return (self.goal - percentage_grade) * 100 / none_weights
    else:
      return self.goal - percentage_grade

courses = {}
try:
  with open('gpa_save.pkl', 'rb') as save:
    courses = pickle.load(save)
except:
  print('uwu no save found~ but you cant see this message~')

while True:
  os.system(CLEARCMD)

  print('——————————— courses ————————————')
  if len(courses) == 0:
    print('no courses added yet~')
    print()
  else:
    for course in courses.values():
      g1, g2, g3 = course.grades
      print(f'{course.name} ({course.credits} creds): {round(g1, 1)}% | {g3} | {g2}')
      for item, score in course.scores.items():
        print(f' - {item} ({course.weights[item]}%): {score}%')
      print(f'{round(course.passing, 1)}% to reach goal ({course.goal}%)')
      print()

    t_credits = sum([i.credits for i in courses.values()])
    t_score = statistics.mean([i.grades[0] for i in courses.values()])
    t_gpa = statistics.mean([i.grades[2] for i in courses.values()])
    print(f'total ({t_credits}): {t_score}% | {t_gpa}')
    print()

  print('——————————— commands ———————————')
  print(': add [name] [credits] [weights]')
  print(': set [course] [item] [score]')
  print(': goal [course] [score]')
  print(': q')
  print()

  print('————————————————————————————————')
  params = input(': ').split(' ')

  match params[0]:
    case 'add':
      name, credits, *temp = params[1:]
      weights = {}
      for i in range(0, len(temp), 2):
        weights[temp[i]] = int(temp[i + 1])
      courses[name] = Course(name, int(credits), weights)

    case 'set':
      name, item, score = params[1:]
      courses[name].scores[item] = int(score)

    case 'goal':
      name, score = params[1:]
      courses[name].goal = int(score)

    case 'q':
      with open('gpa_save.pkl', 'wb') as save:
        pickle.dump(courses, save, pickle.HIGHEST_PROTOCOL)
      os.system(CLEARCMD)
      exit()