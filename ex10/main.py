import threadbind

c = threadbind.Channel(850, 40, 2, 3)  # max time, number iterations, number producers, number consumers

c.start()