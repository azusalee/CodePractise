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
        
        let font = UIFont.systemFont(ofSize: 15)
        let label1 = UILabel.init(frame: CGRect.init(x: 50, y: 50, width: 200, height: 100))
        label1.font = font
        label1.numberOfLines = 0
        label1.text = "哈哈哈哈哈哈\n哈哈哈哈哈哈\n哈哈哈哈哈哈"
        self.view.addSubview(label1)
        
        let param = NSMutableParagraphStyle()
        param.lineSpacing = 0
        let label2 = UILabel.init(frame: CGRect.init(x: 50, y: 200, width: 200, height: 100))
        label2.numberOfLines = 0
        label2.attributedText = NSAttributedString.init(string: "哈哈哈哈哈哈\n哈哈哈哈哈哈\n哈哈哈哈哈哈", attributes: [.paragraphStyle: param, .font: font])
        self.view.addSubview(label2)
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

