import sys 
from math import * 

PHI = radians(float(sys.argv[1]))   #radians(float(input("pressure angle"))) 
PC = float(sys.argv[2]) #float(input("Circular Pitch (module)")) 
teeth = int(sys.argv[3])  #input("no of teeth")

def involute_intersect_angle(Rb, R): 
    Rb, R = float(Rb), float(R) 
    return (sqrt(R**2 - Rb**2) / (Rb)) - (acos(Rb / R)) 

def point_on_circle(radius, angle): 
    x = radius * cos(angle) 
    y = radius * sin(angle) 
    return (x, y) 

def points_to_svgd(p): 
    f = p[0] 
    p = p[1:] 
    svgd = 'M%s,%s' % f 
    for x in p: 
        svgd += 'L%s,%s' % x 
    svgd += 'z' 
    return svgd 

def gear(N,phi=PHI,Pc=PC): 
    #Pitch Circle 
    D = N * Pc / pi 
    R = D / 2.0 
    
    #Diametrial pitch 
    Pd = N / D 
    
    #Base Circle 
    Db = D * cos(phi) 
    Rb = Db / 2.0 
    
    #Addendum 
    a = 1.0 / Pd 
    
    #Outside Circle 
    Ro = R + a 
    Do = 2 * Ro 
    
    #Tooth thickness 
    T = (pi * D) / (2 * N) 
    
    #undercut? 
    U = (2 / (sin(phi) ** 2)) 
    needs_undercut = N < U 
    sys.stderr.write("N:%s R:%s Rb:%s\n" % (N,R,Rb)) 
    
    
    #Clearance 
    c = 0.0 
    #Dedendum 
    b = a + c 
    
    #Root Circle 
    Rr = R - b 
    Dr = 2 * Rr     
    
    two_pi = 2 * pi 
    half_thick_angle = two_pi / (4 * N) 
    pitch_to_base_angle = involute_intersect_angle(Rb, R) 
    pitch_to_outer_angle = involute_intersect_angle(Rb, Ro) - pitch_to_base_angle 
    
    #print degrees(half_thick_angle),degrees(pitch_to_base_angle),degrees(pitch_to_outer_angle) 
    centers = [(x * two_pi / N) for x in range(N)] 
    
    points = [] 
    
    for c in centers: 
        #angles 
        pitch1 = c - half_thick_angle 
        base1 = pitch1 - pitch_to_base_angle 
        outer1 = pitch1 + pitch_to_outer_angle 
        
        pitch2 = c + half_thick_angle 
        base2 = pitch2 + pitch_to_base_angle 
        outer2 = pitch2 - pitch_to_outer_angle 
        
        #points 
        b1 = point_on_circle(Rb, base1) 
        p1 = point_on_circle(R, pitch1) 
        o1 = point_on_circle(Ro, outer1) 
        o2 = point_on_circle(Ro, outer2) 
        p2 = point_on_circle(R, pitch2) 
        b2 = point_on_circle(Rb, base2) 
        
        if Rr >= Rb: 
            pitch_to_root_angle = pitch_to_base_angle - involute_intersect_angle(Rb, Rr) 
            root1 = pitch1 - pitch_to_root_angle 
            root2 = pitch2 + pitch_to_root_angle 
            r1 = point_on_circle(Rr, root1) 
            r2 = point_on_circle(Rr, root2) 
            p_tmp = [r1,p1,o1,o2,p2,r2] 
        else: 
            r1 = point_on_circle(Rr, base1) 
            r2 = point_on_circle(Rr, base2) 
            p_tmp = [r1,b1,p1,o1,o2,p2,b2,r2] 
            
        points.extend(p_tmp) 
        
    svgd = points_to_svgd(points) 
    
    svg = """ 
    <g> 
    <path style="fill:gray;fill-opacity:0.5;stroke:black;" d="%s"/> 
    </g> 
    """ % (svgd) 
    
    fo = open("file.svg", "w+")
    fo.write("<svg>\n" + svg + "</svg>\n");
	# Close opend file
    fo.close()

gear(teeth) 
