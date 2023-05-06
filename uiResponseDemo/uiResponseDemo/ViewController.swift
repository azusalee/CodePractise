//
//  ViewController.swift
//  uiResponseDemo
//
//  Created by lizihong on 2023/5/6.
//

import UIKit

class ViewController: UIViewController, UIGestureRecognizerDelegate {
    
    let myView = MyView.init(frame: CGRect(x: 50, y: 50, width: 200, height: 200))

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        let gesture = UITapGestureRecognizer.init(target: self, action: #selector(viewDidTap(gesture:)))
        //gesture.delegate = self
        self.view.addGestureRecognizer(gesture)
        
        myView.backgroundColor = UIColor.red
        
        self.view.addSubview(myView)
        
        let button = UIButton.init(frame: CGRect.init(x: 50, y: 300, width: 200, height: 200))
        button.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        button.addTarget(self, action: #selector(buttonDidTap(button:)), for: .touchUpInside)
        self.view.addSubview(button)
        
        let subView1 = UIView(frame: CGRect.init(x: 50, y: 300, width: 200, height: 200))
        subView1.backgroundColor = UIColor.blue
        self.view.addSubview(subView1)
        
    }
    
    @objc
    private func buttonDidTap(button: UIButton) {
        print("调用 viewController buttonDidTap(button: UIButton)")
    }

    @objc
    private func viewDidTap(gesture: UITapGestureRecognizer) {
        print("调用 viewController viewDidTap(gesture: UITapGestureRecognizer)")
    }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        print("调用 viewController touchesBegan(gesture: UITapGestureRecognizer)")
        super.touchesBegan(touches, with: event)
        
    }

    public func gestureRecognizerShouldBegin(_ gestureRecognizer: UIGestureRecognizer) -> Bool {
        
        
        return true
    }
}

